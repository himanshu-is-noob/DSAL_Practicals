def linear_probing(telephone_no):
    for i in range(size):
        index = (telephone_no + i) % size
        if hash_table[index] == -1:
            hash_table[index] = telephone_no
            print("Record Inserted")
            return
    print("Table Full, Record Cannot be Inserted")

def quadratic_probing(telephone_no):
    for i in range(size):
        index = (telephone_no % size + i * i) % size
        if hash_table[index] == -1:
            hash_table[index] = telephone_no
            print("Record Inserted")
            return
    print("Element Cannot be Inserted")

def search(telephone_no):
    count = 0
    for i in range(size):
        index = (telephone_no + i) % size
        if hash_table[index] == telephone_no:
            print("Element Found at index", index)
            print("Required record:", hash_table[index])
            print("No. of comparisons =", count + 1)
            return
        count += 1
    print("Record not found")

def display():
    print("Index  Telephone number")
    for i in range(size):
        if hash_table[i] != -1:
            print(i, "     ", hash_table[i])

size = int(input("Enter the table size: "))
n = int(input("Enter no. of records to be inserted: "))
hash_table = [-1] * size

while True:
    print("\n1. Insert record using linear probing")
    print("2. Insert record using quadratic probing")
    print("3. Search")
    print("4. Display records")
    print("5. Exit")
    
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        for _ in range(n):
            telephone_no = int(input("Enter the telephone number: "))
            linear_probing(telephone_no)
    elif choice == 2:
        for _ in range(n):
            telephone_no = int(input("Enter the telephone number: "))
            quadratic_probing(telephone_no)
    elif choice == 3:
        telephone_num = int(input("Enter the number to be searched: "))
        search(telephone_num)
    elif choice == 4:
        display()
    elif choice == 5:
        print("Program Exited")
        break
    else:
        print("Invalid choice")