'''
    Exercise 4: Intermediate - Set Comprehensions and Filtering
    Task: Given a list of numbers, use a set comprehension to create 
    a set of squares of all the even numbers from the list. Then, 
    filter out squares that are greater than 50.

    Exercise 5: Intermediate - Finding Common Elements in Multiple Sets
    Task: Given three sets of integers, find the elements that are common 
    to all three sets.

    Exercise 6: Difficult - Set Operations with Complex Data Structures
    Task: Given a list of dictionaries where each dictionary represents 
    a student with id and name, find the set of unique student names. 
    Then, given another list of dictionaries representing students who 
    have passed a course, find the set of student names who did not pass 
    the course.
'''

def filter_squares(mylist):
    myset = set(mylist)
    #set of squares of all the even numbers from the list
    myset = {x**2 for x in myset if x%2 == 0}

    #filter out squares that are greater than 50.
    myset = {x for x in myset if x <= 50}
    return myset

def common_elements(set1, set2, set3):
    
    return set1.intersection(set2).intersection(set3)

def get_unique_student_names(students):
    return {student['name'] for student in students }

def get_student_names_who_did_not_pass(students, passed_students):

    unique_student_names = get_unique_student_names(students)
    passed_student_names = {student['name'] for student in passed_students}

    return unique_student_names.difference(passed_student_names)

# List of numbers
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# Printing the results, exersice 4
#print("Filtered squares:", filter_squares(numbers))

# Creating three sets of integers
set1 = {1, 2, 3, 4, 5}
set2 = {3, 4, 5, 6, 7}
set3 = {5, 6, 7, 8, 9}

# Printing the results exersice 5
#print("Common elements in all three sets:", common_elements(set1, set2, set3))


# Printing the results, exersice 6
# List of dictionaries representing students
students = [
    {'id': 1, 'name': 'Alice'},
    {'id': 2, 'name': 'Bob'},
    {'id': 3, 'name': 'Charlie'},
    {'id': 4, 'name': 'David'},
    {'id': 5, 'name': 'Alice'}
]

# List of dictionaries representing students who passed the course
passed_students = [
    {'id': 2, 'name': 'Bob'},
    {'id': 4, 'name': 'David'}
]

# Printing the results
print("Unique student names:", get_unique_student_names(students))
print("Student names who did not pass:", get_student_names_who_did_not_pass(students, passed_students))