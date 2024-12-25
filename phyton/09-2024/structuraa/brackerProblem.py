def validate_program(length, program):
    stack = []
    matching = {')': '(', ']': '[', '}': '{'}
    for i, char in enumerate(program):
        if char in '({[':
            stack.append((char, i))
        elif char in ')}]':
            if not stack:
                return f"{char} {i}"
            last_open, open_index = stack.pop()
            if matching[char] != last_open:
                return f"{char} {i}"
    if stack:
        return f"ok so far"
    return "ok so far"
length = int(input())
program = input()
print(validate_program(length, program))
