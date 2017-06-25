% /**
%  * 
%  * @author:		胡文博
%  * @email:		huwenbo@mail.dlut.edu.cn
%  * @dateTime:		2017-06-12 16:01:06
%  * @description: 	SSTF调度算法
%  */
function [responseVec,movingArmNum] = SSTF(startPoint,accessSequence)
    responseVec = zeros(length(accessSequence)+1);
    responseVec(1) = startPoint;%响应序列第一数为起始位置
    movingArmNum = 0;%记录移臂总数
    for i = 2:length(responseVec)
		%寻找距离当前磁臂最近的磁道访问请求
        [step,index] = min(abs(accessSequence-responseVec(i-1)) );
        movingArmNum = movingArmNum + step;
        responseVec(i) = accessSequence(index);
        accessSequence(index) = [];
    end
end
