var
    n, ans: Int64;
    
begin
    Read(n);
    
    ans := n div 2;
    if n mod 2 = 1 then
        ans := ans - n;
    
    Write(ans);
end.