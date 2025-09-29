if __name__ == "__main__":
    while True:
        print("\n=== String Operations ===")
        print("1. Reverse String")
        print("2. Check Palindrome")
        print("3. Concatenate Strings")
        print("4. Word Count")
        print("5. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            s = input("Enter a string: ")
            print("Reversed string:", reverse_string(s))

        elif choice == "2":
            s = input("Enter a string: ")
            if is_palindrome(s):
                print("The string is a palindrome.")
            else:
                print("The string is not a palindrome.")

        elif choice == "3":
            s1 = input("Enter first string: ")
            s2 = input("Enter second string: ")
            print("Concatenated string:", concatenate_strings(s1, s2))

        elif choice == "4":
            s = input("Enter a string: ")
            print("Word count:", word_count(s))

        elif choice == "5":
            print("Exiting...")
            break

        else:
            print("Invalid choice. Try again.")
