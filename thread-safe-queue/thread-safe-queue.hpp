#ifndef __THREADSAFEQUEUE__
#define __THREADSAFEQUEUE__

#include <condition_variable>
#include <mutex>
#include <queue>

#include <chrono>
#include <memory>
#include <thread>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

extern std::shared_ptr<spdlog::logger> myLogger;

template <typename T>
class IThreadSafeQueue
{
   public:
    /**
     * @brief Pure virtual method for puting an element into the queue
     *
     * @param element The element to be inserted into the queue.
     */
    virtual void put(T &&element) = 0;

    /**
     * @brief Pure virtual method for puting an element into the queue with priority
     *
     * @param element The element to be inserted into the queue.
     */
    virtual void put_prioritized(T &&element) = 0;

    /**
     * @brief Pure virtual method for puting an element into the queue
     *
     * @param element A constant reference to the element to be inserted into the queue.
     */
    virtual void put(T const &element) = 0;

    /**
     * @brief Pure virtual method for popping an element from the queue in a "wait indefinitely
     * until new element is available" fashion
     *
     * @return Shared pointer to the element popped.
     */
    virtual std::shared_ptr<T> wait_and_pop() = 0;

    /**
     * @brief Pure virtual method for popping an element from the queue in a "wait for a timeout
     * until new element is available" fashion
     *
     * @param timeout Timeout in milliseconds to wait for new element
     * @note In the event of a timeout, a nullptr will be returned
     */
    virtual std::shared_ptr<T> wait_and_pop_for(const std::chrono::milliseconds &timeout) = 0;

    /**
     * @brief Pure virtual method for popping an element from the queue in a "wait indefinitely
     * until new element is available" fashion.
     *
     * @param element Reference to the popped element
     *
     * @return boolean that is true in case of a sucessful pop nad false in case of empty queue
     */
    virtual bool wait_and_pop2(T &element) = 0;

    /**
     * @brief Pure virtual method for checking whether the queue is empty
     *
     * @return boolean that is true in case of the queue being empty
     */
    virtual bool empty() = 0;

    /**
     * @brief Pure virtual method for re-creating the underlying data structure (throwing away all
     * current elements)
     */
    virtual void reset() = 0;

    /**
     * @brief Pure virtual method for clearing the underlying data structure
     */
    virtual void clear() = 0;
};

/**
 * @brief Implements the interface defined in class IThreadSafeQueue. In this
 * case, the underlying data structure is a std::dequeue<T>
 * @see IThreadSafeQueue<T>
 */
template <typename T>
class ThreadSafeQueue : public IThreadSafeQueue<T>
{
   public:
    /**
     * @brief Construct a new Thread Safe Queue object
     *
     */
    ThreadSafeQueue()
    {
    }

    /**
     * @brief Overrides the method void put(T &&element) of the interface class
     */
    virtual void put(T &&element) override

    {
        {
            std::scoped_lock<std::mutex> lock(m_mutex);
            m_queue.push_back(std::forward<T>(element));
        }
        m_cv.notify_all();
    }

    /**
     * @brief Overrides the method void put_prioritized(T &&element) of the interface class
     */
    virtual void put_prioritized(T &&element) override

    {
        {
            std::scoped_lock<std::mutex> lock(m_mutex);
            m_queue.push_front(std::forward<T>(element));
        }
        m_cv.notify_all();
    }

    /**
     * @brief Overrides the method void put(T const &element) of the interface class
     */
    virtual void put(T const &element) override

    {
        {
            std::scoped_lock<std::mutex> lock(m_mutex);
            m_queue.push_back(element);
        }
        m_cv.notify_all();
    }

    /**
     * @brief Overrides the method std::shared_ptr<T> wait_and_pop() of the interface class
     */
    virtual std::shared_ptr<T> wait_and_pop() override

    {
        std::shared_ptr<T>           result;
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cv.wait(lock, [&]() { return !m_queue.empty(); });
        result = std::make_shared<T>(std::move(m_queue.front()));
        m_queue.pop_front();
        lock.unlock();
        return result;
    }

    /**
     * @brief Overrides the method std::shared_ptr<T> wait_and_pop_for(const
     * std::chrono::milliseconds &timeout) of the interface class
     */
    virtual std::shared_ptr<T> wait_and_pop_for(const std::chrono::milliseconds &timeout) override

    {
        std::shared_ptr<T>           result;
        std::unique_lock<std::mutex> lock(m_mutex);
        if (m_cv.wait_for(lock, timeout, [&]() { return !m_queue.empty(); }))
        {
            result = std::make_shared<T>(std::move(m_queue.front()));
            m_queue.pop_front();
            lock.unlock();
        }
        return result;
    }

    /**
     * @brief Overrides the method bool wait_and_pop(T &element) of the interface class
     */
    virtual bool wait_and_pop2(T &element) override

    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cv.wait(lock, [&]() { return !m_queue.empty(); });
        element = m_queue.front();
        m_queue.pop_front();
        lock.unlock();
        return true;
    }

    /**
     * @brief Overrides the method bool empty() of the interface class
     */
    virtual bool empty() override

    {
        bool result;
        {
            std::scoped_lock<std::mutex> lock(m_mutex);
            result = m_queue.empty();
        }
        return result;
    }

    /**
     * @brief Overrides the method void reset() of the interface class
     */
    virtual void reset() override

    {
        m_queue = std::deque<T>{};
    }

    /**
     * @brief Overrides the method void clear() of the interface class
     */
    virtual void clear() override

    {
        m_queue.clear();
    }

   private:
    std::deque<T>           m_queue{};
    std::condition_variable m_cv;
    std::mutex              m_mutex;
};
void test_queue();

#endif