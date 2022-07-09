# AUTHOR: ASHWIN ABRAHAM

subjfile = open("subject.txt", "r")
objfile = open("object.txt", "r")
verbfile = open("verb.txt", "r")

subj = [s.strip() for s in subjfile]
obj = [o.strip() for o in objfile]
verb = [v.strip() for v in verbfile]

pronouns = ["me", "us", "her", "him", "it", "them", "I", "We", "She", "He", "It", "They"]

for a in subj:
    for b in verb:
        for c in obj:
            print(("" if a in pronouns else "The ")+a, b+"ed", ("" if c in pronouns else "the ")+c)
            print(("" if a in pronouns else "The ")+a, b+"s", ("" if c in pronouns else "the ")+c)
            print(("" if a in pronouns else "The ")+a, "will "+b, ("" if c in pronouns else "the ")+c)

subjfile.close()
objfile.close()
verbfile.close()