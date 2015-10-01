
dictionary = open("dict.txt", 'r')
new_dict = open("new_dict.txt", 'w')
for line in dictionary:
    if len(line) < 15:
        new_dict.write(line)

