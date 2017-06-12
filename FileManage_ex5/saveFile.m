% /**
%  * 
%  * @author:		胡文博
%  * @email:		huwenbo@mail.dlut.edu.cn
%  * @dateTime:		2017-06-11 22:58:16
%  * @description: 	
%  */
function  [bitMap,files] =saveFile( bitMapRaw, fileName, fileSize )
    bitMap = bitMapRaw;
    files.len = fileSize;
    files.name = fileName;
    fileSize = ceil(fileSize/2);
    cnt = 0;
    result = 0;
    for indexi = 1:size(bitMapRaw,1)
        for indexj = 1:size(bitMapRaw,2)
            if(bitMapRaw(indexi,indexj) > 0)
                cnt = 0;
                continue;
            end
            cnt = cnt+1;
            if(cnt >= fileSize)
                result = 1;
                break;
            end
        end
        if(result == 1)
            break;
        end
    end
    if(result == 0)
        error (['Disk has no space for file',(fileName)]);
    end
    bitNum = size(bitMapRaw,2)*(indexi - 1)+indexj - (fileSize-1);
    files.start = bitNum;
    startj = mod(bitNum-1, size(bitMapRaw,2) ) + 1;
    starti = (bitNum - startj)/size(bitMapRaw,2) + 1;
    for i = starti:indexi
        if (i == starti)
            s = startj;
        else
            s = 1;
        end
        if(i == indexi)
            e = indexj;
        else
            e = size(bitMap,2);
        end
        bitMap(i,s:e) = 1;
    end
end