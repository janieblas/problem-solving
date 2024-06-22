'''
    Exercise 1: Basic - Creating and Modifying a Set
    Task: Create a set of five different fruits. Add one more fruit to the set and 
    then remove one fruit from the set.

    Exercise 2: Basic - Set Operations
    Task: Given two sets of integers, find their union, intersection, and difference.

    Exercise 3: Intermediate - Removing Duplicates and Finding Unique Elements
    Task: Given a list of integers with some duplicates, remove the duplicates and 
    then find the elements that are unique to either of two lists.
'''

## exersice 1
myset = {"aple", "mango", "banana", "watermelon", "wiki"}
print(myset)
myset.add("grape")
print(myset)
myset.remove("aple")
print(myset)

## exersice 2
myintset1 = {1, 2, 3, 4, 5}
myintset2 = {4, 5, 6, 7, 8}

union_set = myintset1.union(myintset2)

intersection_set = myintset1.intersection(myintset2)

difference_set = myintset1.difference(myintset2)

print("union: ",union_set)
print("intersection: ",intersection_set)
print("differnce: ",difference_set)

## exersice 3
# List of integers with duplicates
list1 = [1, 2, 2, 3, 4, 4, 5]
list2 = [4, 4, 5, 6, 7, 7, 8]

myset1 = set(list1)
myset2 = set(list2)

unique_elements = myset1.symmetric_difference(myset2)

print(unique_elements)