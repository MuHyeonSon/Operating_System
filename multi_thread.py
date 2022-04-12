import threading
import time

#스레드에서 실행할 함수
def thread_func(x_num,start,end,r):
    print("[Sub-Thread] %d: 시작합니다." %x_num)
    
    s = 0
    for i in range(start,end):
        s += i
        #time.sleep(0.1)
    r.append(s)
    print("[Sub-Thread]%d: 종료합니다." %x_num)
    return
    
#메인 영역

if __name__ == "__main__":
    print("[Main-Thread] 서브스레드 시작 전")
    
    start, end = 1,1001
    r = []
    
    x1 = threading.Thread(target=thread_func, args=(1,1,201,r))
    x2 = threading.Thread(target=thread_func, args=(2,201,401,r))
    x3 = threading.Thread(target=thread_func, args=(3,401,601,r)) 
    x4 = threading.Thread(target=thread_func, args=(4,601,801,r))
    x5 = threading.Thread(target=thread_func, args=(5,801,1001,r))   

    print("[Main-Thread] 서브스레드 시작")
    
    x1.start() #서브 스레드 시작
    x2.start() #서브 스레드 시작
    x3.start() #서브 스레드 시작
    x4.start() #서브 스레드 시작
    x5.start() #서브 스레드 시작
    
    print("[Main-Thread] 스레드 종료를 기다립니다.")
    
    x1.join() # join()추가
    x2.join() # join()추가
    x3.join() # join()추가
    x4.join() # join()추가
    x5.join() # join()추가

    print(f'1부터 1000까지의 합은 {s} 입니다.')
    
    print("[Main-Thread] 프로그램을 종료합니다.")
