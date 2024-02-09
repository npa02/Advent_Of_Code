spell_to_number = {
    "one": '1', "two": '2', "three": '3', "four": '4', "five": '5',
    "six": '6', "seven": '7', "eight": '8', "nine": '9'
}

def replace_spell(input_str):
    result = list(input_str)

    for spell, number in spell_to_number.items():
        pos = input_str.find(spell)

        while pos != -1:
            # Replace the second and subsequent characters with the digit
            result[pos + 1] = number

            # Move the position to the next character after the replaced digit
            pos = input_str.find(spell, pos + 1)

    return result


sum_result = 0

with open("1st_day/input.txt", "r") as inputFile:
    for line in inputFile:
        num_string = ""
        line = line.strip()
        replaced_line = replace_spell(line)

        for char in replaced_line:
            if char.isdigit():
                num_string += char
                break

        for char in reversed(replaced_line):
            if char.isdigit():
                num_string += char
                break

        if num_string:
            sum_result += int(num_string)

print("Sum =", sum_result)
