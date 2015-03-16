#! /usr/bin/python2.7
import pickle
import itertools
pkl_file = open('data.pkl', 'rb')
wdict = pickle.load(pkl_file)
word =""
word = raw_input("your letters are: ")
while(word != ''):
    word = ''.join(sorted(word))
    for i in range(len(word), 0, -1):
        sets = set(itertools.combinations(word, i))
        words = []
        for s in sets:
            sub = ''.join(sorted(s))
            if sub in wdict:
                words = words + wdict[sub]
        if(words != []):
            print("words of length %s" % i)
            print(words)
            print('\n')
    print('\n\n\n')
    word = raw_input("your letters are: ")
