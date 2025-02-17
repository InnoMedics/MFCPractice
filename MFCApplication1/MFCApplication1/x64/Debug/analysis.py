import sys
import os

def analyze_images(image_paths):
    print("이미지 경로 수:", len(image_paths))  # 디버깅용 출력
    sys.stdout.flush()  # 출력 버퍼 비우기 (MFC가 즉시 읽을 수 있도록)

    for path in image_paths:
        if not os.path.exists(path):
            print(f"파일 없음: {path}")
            sys.stdout.flush()
            return "오류 발생"

    return "확인"

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("이미지 없음")
        sys.stdout.flush()
        sys.exit(1)

    image_files = sys.argv[1:]
    result = analyze_images(image_files)
    
    print(result)
    sys.stdout.flush()  # MFC에서 읽을 수 있도록 버퍼 비우기

