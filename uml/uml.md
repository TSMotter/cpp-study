# UML - Unified Modeling Language

- Integrated set of diagrams in various shapes and forms that can be used to define, design, visualize, document software systems and business models 

## Structural diagrams
- Composite structure diagram
- Package diagram
- Object diagram
- Deployment diagram
- Profile diagram
- **Class diagram**
- Component diagram

## Behavioral diagrams 
- Activity diagram
- State machine diagram
- Use case diagram
- Interaction diagram -> sequence diagram
- Interaction diagram -> communication diagram
- Interaction diagram -> interaction overview diagram
- Interaction diagram -> timing diagram

### Class diagrams

- 3 levels of specification
  - Conceptual Perspective
    - Diagrams are interpreted as describing entities of the real world (concepts in that domain)
    - These real world entities are represented as classes
    - Language independent
  - Specification Perspective
    - Diagrams are interpreted as representing abstraction of software or components
    - May contain interfaces or specifications, but no specific implementation
  - Implementation Perspective
    - Diagrams are interpreted as a description of software implementation in a particular language

### Relationships between classes

- **Inheritance:**
  - It models a "is" relationship
  - *Example:* A policeCar inherits from Car
    - A police car IS a car

- **Realization or Implementation:**
  - Normally depicts the relationship between an interface classes and classes that implement that interface

- **Association:**
  - All object have their own lifecycle and there is no ownership relation. 
  - There can be a multiplicity in the relationship: The number of objects that can take part on the relationship
    - 1 student can learns_from() X teachers
    - 1 teacher can teach() X students
  - *Example:* A teacher and student. Multiple students can associate with a single teacher and single student can associate with multiple teachers.
    - There is no ownership between the objects and both have their own lifecycle. Both can create and delete independently.
    - Maybe a method teach() inside the teacher class requires a student object to act upon, and the other way around: a method learn_from() inside student class requires a teacher object
    - But, in this context, a teacher is NOT a student and a student is NOT a teacher

  - **Dependency:**
    - Is a special case of Association
    - It models a "uses" relationship
    - A dependency exists between two elements if changes to the definition of one element (the supplier) may cause changes to the other (the client)
    - When an object of one class uses an object of another class and this object is not stored in any fields
    - Changes in one class will mean changes in the other
    - *Example:* Person class has a "hasRead(book)" method. If the book object has changed, then it's not possible anymore to say that the person object has read the book

  - **Composition:**
    - Is a special case of Association
    - It models a "has" relationship
    - There is a "death relationship", ie: The object of class that is owned by the object of it's owning class cannot live on it's own
    - *Example:* A mariage is composed of a wife and husband. The mariage is destroyed if the wife no longer exists
    - *Example:* of a Car and an engine that is very specific to that car (meaning it cannot be used in any other car). This type of relationship between Car and SpecificEngine class is called Composition. An object of the Car class cannot exist without an object of SpecificEngine class and object of SpecificEngine has no significance without Car class. To put in simple words Car class solely "owns" the SpecificEngine class.
      - "A Car of this model has a SpecificEngine in it"

  - **Aggregation:**
    - Is a special case of Association
    - It models a "has" relationship
    - All object have their own lifecycle but there is ownership and child object can not belong to another parent object
    - *Example:* A department and teacher. A single teacher can not belong to multiple departments, but if we delete the department, the teacher object will not be destroyed
      - "A department has teachers in it"
    - *Example:* A workspace has chair, desk and computer. If we delete the workspace, the chair, desk and computer continue existing on their own even though they no longer form an aggregated class "workspace"
      - "A department has teachers in it"