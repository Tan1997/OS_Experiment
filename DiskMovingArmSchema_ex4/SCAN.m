% /**
%  * 
%  * @author:        胡文博
%  * @email:        huwenbo@mail.dlut.edu.cn
%  * @dateTime:        2017-06-12 16:00:49
%  * @description:     SCAN调度算法
%  */
function [responseVec,movingArmNum] = SCAN(startPoint,accessSequence)
    Infinity = 10000000000000;%正无穷
    responseVec = zeros(length(accessSequence)+1,1);
    responseVec(1) = startPoint;%响应序列第一数为起始位置
    movingArmNum = 0;%记录移臂总数
    % 确定首次移臂的方向
    [~,index] = min(abs(accessSequence-startPoint) );
    if(accessSequence(index) >= startPoint)
        direction = 1;
    else
        direction = -1;
    end  
    for i = 2:length(responseVec)
        % 如果当前方向为向外且当前磁臂位置大于剩余访问序列中的最大值
        % 或者当前方向为向内且当前磁臂位置大于剩余访问序列中的最小值
        % 则方向取反
        if( (direction==1 && responseVec(i-1) > max(accessSequence)) ...
            || (direction == -1 && responseVec(i-1) < min(accessSequence))...
            )
            direction = 0-direction;
        end
        tmp = accessSequence-responseVec(i-1);
        if(direction == 1)
            tmp(tmp<=0) = Infinity;
        else
            tmp(tmp>=0) = -Infinity;
        end
        %在不改变方向的前提下寻找距离当前磁臂最近的访问请求
        [step,index] = min(abs(tmp));
        movingArmNum = movingArmNum + step;
        responseVec(i) = accessSequence(index) ;
        accessSequence(index) = [];
    end
end