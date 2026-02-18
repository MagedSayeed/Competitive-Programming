 auto mrg=[&](array<int , 3> x , array<int, 3>y)->array<int , 2>{ // each pair {hshValue1 , hshValue2 , sizeOfsubstring}
        array<int , 2> ret = {x[0] , x[1]};
 
        ret[0]=mul(ret[0] , pw1[y[2]] , MOD1);
        ret[0]=add(ret[0] , y[0] , MOD1);
 
        ret[1]=mul(ret[1] , pw2[y[2]] , MOD2);
        ret[1]=add(ret[1] , y[1] , MOD2);
        return ret;
    };
