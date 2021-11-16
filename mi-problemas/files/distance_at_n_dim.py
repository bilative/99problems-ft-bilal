import numpy as np

def dist(d):
    aa=[]
    for j in range(10000): 
        zz=np.random.random((d,2))
        cc=[]
        for i in range(d):
            cc.append((zz[i,0]-zz[i,1])**2)
        aa.append(np.sqrt(sum(cc)))
    return np.mean(aa)
dist(2)
# 0.5179685748717987
dist(3)
# 0.6644885881507369
dist(4)
# 0.7824394258425867
dist(1000000)
# 408.24848603090726