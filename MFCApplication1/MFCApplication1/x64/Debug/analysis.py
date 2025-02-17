import sys
import os

def analyze_images(image_paths):
    print("�̹��� ��� ��:", len(image_paths))  # ������ ���
    sys.stdout.flush()  # ��� ���� ���� (MFC�� ��� ���� �� �ֵ���)

    for path in image_paths:
        if not os.path.exists(path):
            print(f"���� ����: {path}")
            sys.stdout.flush()
            return "���� �߻�"

    return "Ȯ��"

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("�̹��� ����")
        sys.stdout.flush()
        sys.exit(1)

    image_files = sys.argv[1:]
    result = analyze_images(image_files)
    
    print(result)
    sys.stdout.flush()  # MFC���� ���� �� �ֵ��� ���� ����

