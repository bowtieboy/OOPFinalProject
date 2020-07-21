# Object Oriented Programming Final Project

Create a service desk app where there will be a user interface and an admin interface

User:
The user must enter their first initial attached to their last name, "mlima"
They will be able to select the problem that they are having from the catagories provided, ie. hardware, software, facility, or other.
When the user logs in, they are able to see the status of any issue

Admin:
They must enter a username and a password
They can create a status for the projct, ie. opened, resolved, pending, or unresolved
The admin can see a screen of all the problems orginized by date and shows the problem catagory

Base Class: Client
  Functions:
    Constructor
    Setters
    Getters
    Login - POLYMORPHISM
  Data Members:
    Username
    
  Derived Classes: 
    User:
      Functions:
        Constructor
        CreateIssue
        GetStatus
    Admin:
      Functions:
        Constructor
        Setters
        Getters
        UpdateStatus
        PrintIssues
      Data Members:
        Password

Base Class: Issue
  Functions:
    Constructor
    Setters
    Getters
    PrintOptions - POLYMORPHISM
  Data Members:
    Name
    DateCreated
    IssueType

  Dervied Classes:
    HardwareIssue:
      Functions:
        Constructor
        Setters
        Getters
      Data Members:
        FixCost
    SoftwareIssue:
      Functions:
        Constructors
        Setters
        Getters
      Data Members:
        DebugTime
    FacitiliesIssue:
      Functions:
        Constructors
        Setters
        Getters
      Data Members:
        WorkersNeeded
    OtherIssue:
      Functions:
        Constructors
        Setters
        Getters
      Data Members:
        Description
