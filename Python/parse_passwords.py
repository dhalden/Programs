def make_lops():
    lollipops = []
    passwords = open("10k most common.txt", "r")
    for line in passwords:
        line = line[:-2]
        lollipops.append(line)
    pps = open("parsed_passwords.txt", "w")
    slollipops = str(lollipops)
    pps.write(slollipops)
    pps.close
    return lollipops

def main():
    print make_lops()

if __name__ == "__main__": main()
    


