#4. Write a program that reads in a string and returns a table of the frequency of occurrence of each word. Ignore the case. A sample run of the program would look this
#"The cat in the hat"
#Expected Result :
#The - 2
#Cat - 1
#In - 1
#Hat - 1
string1 = input("Please enter a string: ")
str_list = string1.lower().split(' ')
dict = {}
for i in str_list:
    dict[i] = str_list.count(i)
print(dict)