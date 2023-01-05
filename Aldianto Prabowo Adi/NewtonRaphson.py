# Newton Raphson
# Aldianto Prabowo Adi - 2106146 - Pendidikan Ilmu Komputer

def f(x):
    return x**3 - 3*x - 20

def g(x):
    # Turunan
    return 3*x**2 - 3

def newtonRaphson(x0,e,N):
    print('\n\n== PENERAPAN NEWTON RAPHSON ==')
    step = 1
    flag = 1
    condition = True
    while condition:
        if g(x0) == 0.0:
            print('Error!')
            break
        
        x1 = x0 - f(x0)/g(x0)
        print('Iterasi-%d, x1 = %0.6f dan f(x1) = %0.6f' % (step, x1, f(x1)))
        x0 = x1
        step = step + 1
        
        if step > N:
            flag = 0
            break
        
        condition = abs(f(x1)) > e
    
    if flag==1:
        print('\nAkar yang dibutuhkan adalah: %0.8f' % x1)
    else:
        print('\nTidak Konvergen.')

#Input User
x0 = input('Masukan Tebakan: ')
e = input('Kesalahan yang dapat ditoleransi: ')
N = input('Tahapan Maksimal: ')

x0 = float(x0)
e = float(e)

N = int;
newtonRaphson(x0,e,N)