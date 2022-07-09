# AUTHOR: ASHWIN ABRAHAM

subjfile = open("subject_extended.txt", "r")
objfile = open("object_extended.txt", "r")
verbfile = open("verb_extended.txt", "r")

subj = [s.strip() for s in subjfile]
obj = [o.strip() for o in objfile]
verb = [v.strip() for v in verbfile]

pronouns = ["me", "us", "her", "him", "it", "them", "I", "We", "She", "He", "It", "They"]

def conjugate(verb, tense, person, num):
    # irregular verbs
    if verb == "eat":
        if tense == "present":
            if num == "singular" and person == 3:
                return "eats"
            return "eat"
        if tense == "past":
            return "ate"
        if tense == "future":
            return "will eat"
    
    # verbs ending in e
    if verb[-1] == 'e':
        if tense == "present":
            if num == "singular":
                return verb+"s"
            return verb
        if tense == "past":
            return verb+"d"
    
    if tense == "present":
        if num == "singular":
            return verb+"s"
        return verb
    if tense == "past":
        return verb+"ed"
    return "will " + verb


def person(pronoun):
    if pronoun in ["me", "us", "I", "We"]:
        return 1
    else:
        return 3

def num(pronoun):
    if pronoun in ["us", "We", "them", "They"]:
        return "plural"
    return "singular"
        

def sengen(subj, verb, obj):
    if len(subj) == 0 or len(obj) == 0 or len(verb) == 0:
        return
    if(len(subj) == 1):
        if(len(verb) == 1):
            if(len(obj) == 1):
                print(("" if subj[0] in pronouns else "The ") + subj[0], conjugate(verb[0], "present", person(subj[0]), num(subj[0])), ("" if obj[0] in pronouns else "the ") + obj[0])
                print(("" if subj[0] in pronouns else "The ") + subj[0], conjugate(verb[0], "past", person(subj[0]), num(subj[0])), ("" if obj[0] in pronouns else "the ") + obj[0])
                print(("" if subj[0] in pronouns else "The ") + subj[0], conjugate(verb[0], "future", person(subj[0]), num(subj[0])), ("" if obj[0] in pronouns else "the ") + obj[0])
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