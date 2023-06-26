def gemm(mat1, mat2):
    prod = []
    for row in mat1:
        tmp = []
        for i in range(len(mat2[0])):
            acc = 0
            for j in range(len(row)):
                acc += row[j] * mat2[j][i]
                print(row[j], mat2[j][i])
            tmp.append(acc)
        prod.append(tmp)
        
    return prod
    
def gemv(mat, vec):
    prod = []
    for row in mat:
        sum = 0
        for i in range(len(row)):
            sum += row[i] * vec[i]
        prod.append(sum)
    
    return prod

def fill_matrix(row, col, num):
    mat = []
    for i in range(row):
        mat.append([num] * col)
    
    return mat

def fill_vector(size, num):
    return [num] * size

if __name__ == "__main__":
    print(fill_vector(3,11))
    print(fill_matrix(4,3,11))
    
    matrix = [[3,2,0], [0,4,1], [2,0,1]]
    vector = [4,3,1]
    print(gemv(matrix, vector))
    
    matrix1 = [[1,2,3], [4,5,6]]
    matrix2 = [[7,8], [9,10], [11,12]]
    print(gemm(matrix1, matrix2))
    