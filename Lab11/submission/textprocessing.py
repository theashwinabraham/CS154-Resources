# AUTHOR: ASHWIN ABRAHAM

num_vowels_per_word = [[], [], [], [], [], [], [], [], [], []]

for i in range(10):
    with open(f'TESTDATA/story{i}.txt', 'r') as file:
        for line in file:
            for word in line.split():
                num_vowels_per_word[i].append(word.count('a')+word.count('A')+word.count('e')+word.count('E')+word.count('i')+word.count('I')+word.count('o')+word.count('O')+word.count('u')+word.count('U'))

avg_num_vowels = [(i, sum(x)/len(x)) for i, x in enumerate(num_vowels_per_word)]

avg_num_vowels.sort(reverse = True, key = lambda x: x[1])

print([f'Story {i} has on average {x} vowels per word' for (i, x) in avg_num_vowels][:3])