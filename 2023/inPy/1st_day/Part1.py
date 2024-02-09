with open("1st_day/input.txt", "r") as input_file:
    sum = 0
    for line in input_file:
        num_string = ""
        for char in line:
            if char.isdigit():
                num_string += char
                break

        for char in reversed(line):
            if char.isdigit():
                num_string += char
                break

        # print(num_string)
        sum += int(num_string)

print("Sum =", sum)