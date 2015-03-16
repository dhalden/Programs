#! /usr/bin/python2.7
import pickle
import itertools
pkl_file = open('data.pkl', 'rb')
wdict = pickle.load(pkl_file)
word =""
word = raw_input("your letters are: ")
while(word != ''):
    word = ''.join(sorted(word))
    words = []
    for i in range(len(word)+1, 0, -1):
        sets = set(itertools.combinations(word, i))
        for s in sets:
            sub = ''.join(sorted(s))
            if sub in wdict:
                words = words + wdict[sub]
    print(words)
    word = raw_input("your letters are: ")
    word = word[:len(word)-1]
