###问题###
一个字符串中找到最大不重复的子字符串


###思想###
关键点：
1.两个下标：一个代表起始下标start，一个代表终止下标end
2.数据结构是集合set


思想：
1.如果end下标对应的字符不在集合中，那就加入集合，并且end向后移一位，并更新max的值
2.如果end下标对应的字符在集合中，那就开始从集合中删除start下标对应的字符串，并且向下移动一位start
3.不断重复1和2即可


基本思想就是:
当end遇到在集合中重复的元素的时候，start就开始向上找，同时在集合中删除，直到删除集合中和end下标相同的元素为止！！！
之后start再继续向前进行！！！