# -*- coding: cp949 -*- 

import sys
import os

def analyze_images(image_paths):
    print("�̹��� ��� ��:", len(image_paths))  # ������
    sys.stdout.flush()

    for path in image_paths:
        if not os.path.exists(path):
            print(f"���� ����: {path}")
            sys.stdout.flush()
            return "���� �߻�"

    print("Ȯ��")
    sys.stdout.flush()
    return "Ȯ��"

if __name__ == "__main__":
    print("���̽� ���۵�")  # MFC���� ����Ǵ��� Ȯ�ο�
    sys.stdout.flush()

    if len(sys.argv) < 2:
        print("�̹��� ����")
        sys.stdout.flush()
        sys.exit(1)

    image_files = sys.argv[1:]
    result = analyze_images(image_files)
    
    print(result)
    sys.stdout.flush()


