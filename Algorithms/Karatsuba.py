import time    
def karatsuba(x,y):
    if(len(str(x))==1 or len(str(y))==1):
        return x*y
    n=max(len(str(x)),len(str(y)))
    half=(n//2)
    x0=(x//(10**(half)))
    x1=(x%(10**(half)))
    y0=(y//(10**(half)))
    y1=(y%(10**(half)))
    z0=karatsuba(x0,y0)
    z1=karatsuba(x1,y1)
    z2=karatsuba((x0+x1),(y0+y1))-z0-z1
    z=z0*(10**(2*half))+z2*(10**(half))+z1
    return z
    
if __name__=='__main__':
    a=time.time()
    r=karatsuba(1234,5678)
    b=time.time()
    print(r)
    print('\n')
    print(b-a)
    
