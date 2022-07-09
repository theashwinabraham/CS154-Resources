# AUTHOR: ASHWIN ABRAHAM

num_vowels_per_word = [[], [], [], [], [], [], [], [], [], []]

lengths = []

word_lens = []

for i in range(10):
    with open(f'TESTDATA/story{i}.txt', 'r') as file:
        lengths.append(0)
        word_lens.append(0)
        for line in file:
            lengths[i]+=len(line.split())
            for word in line.split():
                word_lens[i]+=len(word)
                num_vowels_per_word[i].append(word.count('a')+word.count('A')+word.count('e')+word.count('E')+word.count('i')+word.count('I')+word.count('o')+word.count('O')+word.count('u')+word.count('U'))
    word_lens[i] = word_lens[i]/lengths[i]

avg_num_vowels = [sum(x)/len(x) for x in num_vowels_per_word]


author_weightage = [("William Shakespeare", 6.29), ("Brothers Grimm", 4.96), ("Julius Caesar", 11.58)]

def weightage(length, avg_vowel, avg_wordlen):
    return (length + 500*avg_vowel + 100*avg_wordlen)/601


def nearest_author(length, avg_vowel, avg_wordlen):
    return min([(auth, abs(val - weightage(length, avg_vowel, avg_wordlen))) for (auth, val) in author_weightage], key = lambda x: x[1])[0]

for i in range(10):
    print(f'story{i} is most probably written by {nearest_author(lengths[i], avg_num_vowels[i], word_lens[i])}')