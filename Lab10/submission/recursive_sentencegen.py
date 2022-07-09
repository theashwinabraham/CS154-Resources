# AUTHOR: ASHWIN ABRAHAM

subjfile = open("subject.txt", "r")
objfile = open("object.txt", "r")
verbfile = open("verb.txt", "r")

subj = [s.strip() for s in subjfile]
obj = [o.strip() for o in objfile]
verb = [v.strip() for v in verbfile]

pronouns = ["me", "us", "her", "him", "it", "them", "I", "We", "She", "He", "It", "They"]

def sengen(subj, verb, obj):
    if len(subj) == 0 or len(obj) == 0 or len(verb) == 0:
        return
    if(len(subj) == 1):
        if(len(verb) == 1):
            if(len(obj) == 1):
                print(("" if subj[0] in pronouns else "The ") + subj[0], verb[0]+"s", ("" if obj[0] in pronouns else "the ") + obj[0])
                print(("" if subj[0] in pronouns else "The ") + subj[0], verb[0]+"ed", ("" if obj[0] in pronouns else "the ") + obj[0])
                print(("" if subj[0] in pronouns else "The ") + subj[0], "will "+verb[0], ("" if obj[0] in pronouns else "the ") + obj[0])
                return
            sengen(subj, verb, [obj[0]])
            sengen(subj, verb, obj[1:])
            return
        sengen(subj, [verb[0]], obj)
        sengen(subj, verb[1:], obj)
        return
    sengen([subj[0]], verb, obj)
    sengen(subj[1:], verb, obj)
    return

sengen(subj, verb, obj)

subjfile.close()
objfile.close()
verbfile.close()