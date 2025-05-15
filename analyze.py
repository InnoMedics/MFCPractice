import sys
import cv2
import numpy as np

def analyze_image(path_array):
    if len(sys.argv) < 2:
        return("No images provided")
    else:
        return str(len(sys.argv[1:])) + "/" + sys.argv[1]

if __name__ == "__main__":
    image_path = sys.argv
    print(analyze_image(image_path))
