import os

def delete_executables():
    # 현재 디렉토리의 모든 파일 검사
    files = [f for f in os.listdir('.') if os.path.isfile(f)]
    
    # 삭제 대상 실행 파일 리스트
    executables = []
    
    for f in files:
        _, ext = os.path.splitext(f)
        # 1. 확장자가 없거나 .exe 인 경우 (.cpp, .py 등 소스 파일 제외)
        # 2. 실행 권한이 있는 경우 (macOS/Linux)
        if (not ext or ext == '.exe') and os.access(f, os.X_OK):
            # 스크립트 자신이나 숨김 파일은 제외 (필요 시)
            if f == 'clean_exe.py' or f.startswith('.'):
                continue
            executables.append(f)

    if not executables:
        print("현재 디렉토리에 삭제할 실행 파일이 없습니다.")
        return

    print(f"총 {len(executables)}개의 실행 파일을 찾았습니다. 삭제를 시작합니다...")

    deleted_count = 0
    for file_path in executables:
        try:
            os.remove(file_path)
            print(f"[삭제됨] {file_path}")
            deleted_count += 1
        except OSError as e:
            print(f"[에러] {file_path} 삭제 실패: {e}")

    print(f"\n작업 완료: 총 {deleted_count}개의 파일이 삭제되었습니다.")

if __name__ == "__main__":
    delete_executables()
