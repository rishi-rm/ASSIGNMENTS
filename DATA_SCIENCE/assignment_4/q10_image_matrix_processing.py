import numpy as np


def main():
    image = np.array([
        [12, 85, 120, 210, 245],
        [30, 95, 150, 225, 238],
        [48, 110, 175, 205, 255],
        [20, 75, 130, 180, 220],
    ])

    print("\nGrayscale Matrix:\n", image)
    print("Minimum pixel value:", image.min())
    print("Maximum pixel value:", image.max())
    print("Mean intensity:", round(image.mean(), 2))

    threshold = 128
    binary_image = np.where(image >= threshold, 1, 0)
    print("\nBinary image (threshold =", threshold, "):\n", binary_image)
    print("\nSpecific region (rows 1-3, columns 2-5):\n", image[1:3, 2:5])
    print("\nHorizontal flip:\n", np.fliplr(image))
    print("\nVertical flip:\n", np.flipud(image))
    print("\nRow-wise intensity:", image.sum(axis=1).tolist())
    print("Column-wise intensity:", image.sum(axis=0).tolist())


if __name__ == "__main__":
    main()
