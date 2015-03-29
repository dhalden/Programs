#! /usr/bin/python2.7
import pickle
import itertools

pkl_file = open('data.pkl', 'rb')
wdict = pickle.load(pkl_file)
lpts = {'a':1, 'b':3, 'c':3, 'd':2, 'e':1, 'f':4, 'g':2, 'h':3, 'i':1,
        'j':10, 'k':5, 'l':1, 'm':3, 'n':2, 'o':1, 'p':3, 'q':10,'r':1,
        's':1, 't':1, 'u':1, 'v':5, 'w':4, 'x':8, 'y':4, 'z':10}

def print_words(dict_words, mean):
    val=dict_words.items()
    (val.sort(lambda x,y: cmp(y[1],x[1])))
    for t in val:
        if(t[1] >= mean):
            print(t[0], t[1])

def calc_pts(answer):
    tot=0
    for letter in answer:
        tot = lpts[letter] + tot
    if(len(answer) >= 7) and (''.join(sorted(answer)) == word):
        tot += 50
    return tot
 
def create_list(word, i):
    sets = set(itertools.combinations(word, i))
    words = {}
    for s in sets:
        sub = ''.join(sorted(s))
        if sub in wdict:
            for answer in wdict[sub]:
                words[answer] = calc_pts(answer)
    return words 

def calc_mean(words, rm, m):
    mean = 0
    n = 0
    for word in words:
        mean += words[word]
        n += 1
    rm += mean
    m += n
    return mean/n, rm, m


#main, when I figure out how to do this...
word=""
word=raw_input("your letters are: ")
while(word != '' and word != 'exit' and word != 'quit'):
    word = ''.join(sorted(word))
    words = {}
    rm = 0
    m = 0
    running_m = 0
    for i in range(min(len(word), 15), 0 , -1):
        words = create_list(word, i)
        if(words != {}):
            mean, rm, m = calc_mean(words, rm, m)
            print("running mean: %s, mean:" % (rm/m), mean)
            print("words of length %s" % i)
            print_words(words, rm/m)
            print('\n')
    print('\n\n\n')
    word = raw_input("your letters are: ")



