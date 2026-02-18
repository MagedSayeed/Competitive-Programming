auto range=[&](int l , int r)->array<int , 3>{
        array<int , 3>ret={0,0,0};
        for (int i = 0; i < 10; ++i) {
            int f = cnt(i , l , r);
            if(!f)continue;
            int h1{} , h2{};
            h1 =  mul((int)(i+'0') , PrefB1[f-1] , mod1);
            h2 =  mul((int)(i+'0') , prefB2[f-1] , mod2);
            ret=mrg(ret , {h1,h2,f});
        }
        return ret;
    };
/// PrefB1 => prefixSum on powers of Base 
/// cnt => return count of this char in given range 
/// mrg => function to mrg to hashes 
