def add_last(elements, value):
    elements.append(value)

def add_first(elements, value):
    elements.insert(0, value)

def add_after(elements, after_value, value):
    if after_value in elements:
        index = elements.index(after_value) + 1
        elements.insert(index, value)

def remove_element(elements, value):
    while value in elements:
        elements.remove(value)

def process_commands(elements):
    while True:
        command_input = input().strip()
        if command_input == "#":
            break
        parts = command_input.split()
        command = parts[0]
        args = [int(x) for x in parts[1:]]

        if command == "addlast":
            add_last(elements, args[0])
        elif command == "addfirst":
            add_first(elements, args[0])
        elif command == "addafter" and len(args) == 2:
            add_after(elements, args[1], args[0])
        elif command == "remove":
            remove_element(elements, args[0])

# Main execution
n = int(input())  # Number of initial elements
elements = list(map(int, input().split()))  # Initial elements of the list

# Process commands and modify the list accordingly
process_commands(elements)

# Print the final state of the list
print(" ".join(map(str, elements)))
