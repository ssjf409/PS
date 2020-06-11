
        midVal = v[v.size() / 2];
        printf("%d", midVal);
        iter = lower_bound(v.begin(), v.end(), midVal);
        v.erase(iter);