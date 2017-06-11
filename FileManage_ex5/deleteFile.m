function  bitMap =deleteFile( bitMapRaw, fileToDelete)
    bitMap = bitMapRaw;
    blockNum = ceil(fileToDelete.len/2);
    startj = mod(fileToDelete.start - 1,size(bitMapRaw,2)) + 1;
    starti = (fileToDelete.start - startj)/size(bitMapRaw,2) + 1;
    cnt = 0;
    for i = starti:size(bitMapRaw,1)
        for j = startj:size(bitMapRaw,2)
            bitMap(i,j) = 0;
            cnt = cnt +1;
            if(cnt >= blockNum)
                return;
            end
        end
    end
end