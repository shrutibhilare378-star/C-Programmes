import os

FILE_NAME = "books.txt"

def add_book(book_id, title, author, year):
    with open(FILE_NAME, "a") as f:
        f.write(f"{book_id},{title},{author},{year}\n")
    print("Book added successfully.")

def search_book(book_id):
    found = False
    with open(FILE_NAME, "r") as f:
        for line in f:
            record = line.strip().split(",")
            if record[0] == book_id:
                print("Book Found:")
                print(f"ID: {record[0]}, Title: {record[1]}, Author: {record[2]}, Year: {record[3]}")
                found = True
                break
    if not found:
        print("Book not found.")

def update_book(book_id, new_title, new_author, new_year):
    updated = False
    records = []
    with open(FILE_NAME, "r") as f:
        for line in f:
            record = line.strip().split(",")
            if record[0] == book_id:
                records.append(f"{book_id},{new_title},{new_author},{new_year}\n")
                updated = True
            else:
                records.append(line)
    with open(FILE_NAME, "w") as f:
        f.writelines(records)

    if updated:
        print("Book updated successfully.")
    else:
        print("Book ID not found.")

def delete_book(book_id):
    deleted = False
    records = []
    with open(FILE_NAME, "r") as f:
        for line in f:
            record = line.strip().split(",")
            if record[0] != book_id:
                records.append(line)
            else:
                deleted = True
    with open(FILE_NAME, "w") as f:
        f.writelines(records)

    if deleted:
        print("Book deleted successfully.")
    else:
        print("Book ID not found.")

# Example usage
if __name__ == "__main__":
    while True:
        print("\n=== Book Management System ===")
        print("1. Add Book")
        print("2. Search Book")
        print("3. Update Book")
        print("4. Delete Book")
        print("5. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            book_id = input("Enter Book ID: ")
            title = input("Enter Title: ")
            author = input("Enter Author: ")
            year = input("Enter Year: ")
            add_book(book_id, title, author, year)

        elif choice == "2":
            book_id = input("Enter Book ID to search: ")
            search_book(book_id)

        elif choice == "3":
            book_id = input("Enter Book ID to update: ")
            title = input("Enter New Title: ")
            author = input("Enter New Author: ")
            year = input("Enter New Year: ")
            update_book(book_id, title, author, year)

        elif choice == "4":
            book_id = input("Enter Book ID to delete: ")
            delete_book(book_id)

        elif choice == "5":
            print("Exiting...")
            break

        else:
            print("Invalid choice. Try again.")
