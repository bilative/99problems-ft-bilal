def dieSim(n):
    amy_score,tom_score=0,0
    for i in range(n):
        amy=np.random.choice(6)+1
        tom=np.random.choice(6)+1
        if (amy==6):
            amy_score+=1
        elif (tom==6):
            tom_score+=1
    print(f"Tom won {tom_score} times")
    print(f"Amy won {amy_score} times")
    print(amy_score/(amy_score+tom_score))

dieSim(100000)
# Tom won 13938 times
# Amy won 16694 times
# 0.5449856359362758