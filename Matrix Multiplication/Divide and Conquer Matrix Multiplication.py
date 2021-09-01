import random as rn
def dc_multiplication(A,B,N):
    C = [[0 for i in range(N)] for i in range(N)]
    if(N == 1):
        return A[0][0]*B[0][0]
    else:
        mid = N//2
        A11 = [[A[i][j] for j in range(0,mid)] for i in range(0,mid)]
        A12 = [[A[i][j] for j in range(mid,N)] for i in range(0,mid)]
        A21 = [[A[i][j] for j in range(0,mid)] for i in range(mid,N)]
        A22 = [[A[i][j] for j in range(mid,N)] for i in range(mid,N)]
        B11 = [[B[i][j] for j in range(0,mid)] for i in range(0,mid)]
        B12 = [[B[i][j] for j in range(mid,N)] for i in range(0,mid)]
        B21 = [[B[i][j] for j in range(0,mid)] for i in range(mid,N)]
        B22 = [[B[i][j] for j in range(mid,N)] for i in range(mid,N)]
        call1 = dc_multiplication(A11,B11,mid)
        call2 = dc_multiplication(A12,B21,mid)
        call3 = dc_multiplication(A11,B12,mid)
        call4 = dc_multiplication(A12,B22,mid)
        call5 = dc_multiplication(A21,B11,mid)
        call6 = dc_multiplication(A22,B21,mid)
        call7 = dc_multiplication(A21,B12,mid)
        call8 = dc_multiplication(A22,B22,mid)
        #print(call1,call2,call3,call4,call5,call6,call7,call8)
        if(mid == 1):
            C[0][0] = call1 + call2
            C[0][1] = call3 + call4
            C[1][0] = call5 + call6
            C[1][1] = call7 + call8
            #print(C)
            return C
        C11 = [[0 for j in range(0,mid)] for i in range(0,mid)]
        C12 = [[0 for j in range(0,mid)] for i in range(0,mid)]
        C21 = [[0 for j in range(0,mid)] for i in range(0,mid)]
        C22 = [[0 for j in range(0,mid)] for i in range(0,mid)]
        for i in range(0,mid):
            for j in range(0,mid):
                C11[i][j] = call1[i][j] + call2[i][j]
                C12[i][j] = call3[i][j] + call4[i][j]
                C21[i][j] = call5[i][j] + call6[i][j]
                C22[i][j] = call7[i][j] + call8[i][j]
        for i in range(0,mid):
            for j in range(0,mid):
                C[i][j] = C11[i][j]
                C[i][j+mid] = C12[i][j]
                C[i+mid][j] = C21[i][j]
                C[i+mid][j+mid] = C22[i][j]
        #print(C)
        return C
print('Enter the size of the matrix: ')
N = int(input())
A = [[rn.randint(1,9) for j in range(N)] for i in range(N)]
B = [[rn.randint(1,9) for j in range(N)] for i in range(N)]
print('First Matrix: ')
for i in range(N):
        for j in range(N):
            print(A[i][j], end = " ")
        print(end = '\n')
print('Second Matrix: ')
for i in range(N):
    for j in range(N):
        print(B[i][j], end = " ")
    print(end = '\n')
C = dc_multiplication(A,B,N)  
print('Resultant Matrix: ')    
for i in range(N):
    for j in range(N):
        print(C[i][j], end = " ")
    print(end = '\n')