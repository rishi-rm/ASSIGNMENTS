import numpy as np


def main():
    A = np.array([[2, 1, 3], [4, 5, 6], [7, 8, 9]])
    B = np.array([[9, 8, 7], [6, 5, 4], [3, 2, 1]])

    print("\nMatrix A:\n", A)
    print("Matrix B:\n", B)
    print("\nAddition:\n", A + B)
    print("\nSubtraction (A - B):\n", A - B)
    print("\nElement-wise multiplication:\n", A * B)
    print("\nMatrix multiplication (A @ B):\n", A @ B)
    print("\nTranspose of A:\n", A.T)
    print("\nRow-wise sum:", A.sum(axis=1).tolist())
    print("Column-wise sum:", A.sum(axis=0).tolist())
    print("Maximum element:", A.max())
    print("Minimum element:", A.min())

    determinant = np.linalg.det(A)
    print("\nDeterminant of A:", round(determinant, 2))
    if abs(determinant) > 1e-10:
        print("Inverse of A:\n", np.linalg.inv(A))
    else:
        print("Inverse cannot be calculated because the determinant is zero.")


if __name__ == "__main__":
    main()
