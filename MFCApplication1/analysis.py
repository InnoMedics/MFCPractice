# -*- coding: cp949 -*- 

import sys
import os

def analyze_images(image_paths):
    print("이미지 경로 수:", len(image_paths))  # 디버깅용
    sys.stdout.flush()

    for path in image_paths:
        if not os.path.exists(path):
            print(f"파일 없음: {path}")
            sys.stdout.flush()
            return "오류 발생"

    print("확인")
    sys.stdout.flush()
    return "확인"

if __name__ == "__main__":
    print("파이썬 시작됨")  # MFC에서 실행되는지 확인용
    sys.stdout.flush()

    if len(sys.argv) < 2:
        print("이미지 없음")
        sys.stdout.flush()
        sys.exit(1)

    image_files = sys.argv[1:]
    result = analyze_images(image_files)
    
    print(result)
    sys.stdout.flush()


