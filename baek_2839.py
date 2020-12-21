#########시간 부족#############

#a = int(input())

#ans = 0
#num_3 = 1
#remain = (a//5)*5

#while remain%3 != 0:
#    remain= (remain//5)*5
#    num_3 += 1

#ans = remain//5 + num_3       

#print(ans)
###############################

a = int(input())

ans = 0
num_3 = 0
b = (a//5)*5

for i in range(0,5):
    remain = a - b
    if remain % 3 == 0:
        ans = b//5 + remain//3
        break
    b = b-5
    if b <0:
        break
if ans == 0:
    print(-1)
else: 
    print(ans)