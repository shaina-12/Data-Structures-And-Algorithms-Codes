import random as rn
def MatMul(A,B,M,P,N):
    C = [[0 for i in range(M)] for i in range(N)]
    for i in range(0,M):
        for j in range(0,N):
            for k in range(0,P):
                C[i][j] = C[i][j] + (A[i][k]*B[k][j])
    return C
print('Enter the size of the matrix A and matrix B resp: ')
R1 = int(input())
C1 = int(input())
R2 = int(input())    
C2 = int(input())
if(C1 != R2):
    print('Sorry! Matrix Multiplication could not be performed')
else:
    A = [[rn.randint(1,9) for i in range(R1)] for j in range(C1)]
    B = [[rn.randint(1,9) for i in range(R2)] for j in range(C2)]
    print('First Matrix: ')
    for i in range(R1):
        for j in range(C1):
            print(A[i][j], end = " ")
        print(end = '\n')
    print('Second Matrix: ')
    for i in range(R2):
        for j in range(C2):
            print(B[i][j], end = " ")
        print(end = '\n')
    C = MatMul(A,B,R1,C1,C2)
    print('Resultant Matrix: ')
    for i in range(R1):
        for j in range(C2):
            print(C[i][j], end = " ")
        print(end = '\n')

