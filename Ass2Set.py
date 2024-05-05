def create_set(count):
    s=[]
    for i in range(count):
        ele = int(input("Enter Element {} : " .format(i+1)))
        add(s,ele)
    return s 

def get_set(s) :
    return s 

def set_to_string(s) :
    string = "{"
    for i in range(len(s)):
        string = string + str(s[i]) 
        if i != len(s) -1 :
            string = string + ", "
    string = string + "}\n"
    return string

def length (s) :
    return len(s) 

def contains(s,ele):
    return ele in s 

def is_empty(s):
    return len(s) == 0

def add(s,ele):
    if ele not in s :
        s.append(ele)

def remove(s,ele) :
    if ele in s :
        s.remove(ele)

def union(S1,S2):
    new_set = S1[:]
    for ele in S2:
        if ele not in S1 :
            new_set.append(ele)
    return new_set

def Intersection(S1,S2):
    new_set = []
    for ele in S1 : 
        if ele in S2:
            new_set.append(ele)
    return new_set

def difference(S1,S2):
    new_set = []
    for ele in S1:
        if ele not in S2 :
            new_set.append(ele)
    return new_set

def iterator(S1):
    return iter(S1)

def is_subset_of(S1,S2):
    for ele in S1 :
        if ele not in S2 :
            return False
    return True 


n1 = int(input("Enter Size of A Set: "))
S1 = create_set(n1)


n2 = int(input("Enter Size of B Set: "))
S2 = create_set(n2)



print("Length of Set A : " , length(S1))
print("Length of Set B : " , length(S2))

num = int(input("Enter Number to be inserted in Set A :"))
add(S1,num)
print("After Adding Number : " , set_to_string(S1))

ch = str(input("Do u want to Delete Element from A (y/n) : "))

if(ch == 'y' or ch == 'Y'):
    ele = int(input("Enter Number you want to delete Set A :"))
    remove(S1,ele)
    print("After Deletion Set B : " ,set_to_string(S1))



ch = str(input("Do u want to Delete Element from B (y/n) : "))

if(ch == 'y' or ch == 'Y'):
    ele = int(input("Enter Number you want to delete Set B :"))
    remove(S2,ele)
    print("After Deletion Set B : " ,set_to_string(S2))


print("Iterator for Set A : " , list(iterator(S1)))