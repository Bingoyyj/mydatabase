# 功能

* 支持数据库、表的创建、删除

* 支持单主键对大量冷热数据的快速查找
* 支持热数据的增删查改

# 用法

查询已有数据库

```
show databases
```

新建数据库

```
create database database_name
```

删除数据库

```
drop database database_name
```

使用数据库

```
use database database_name
```

新建数据表

```
create table table_name column_num column1 column2 ... columnn
```

删除数据表

```
drop table table_name
```

使用数据表

```
use table table_name
```

插入数据

```
insert column1 column2 ... columnn
```

查找数据

```
search primaryKey
```

删除数据

```
remove primaryKey
```

修改数据

```
alter column1 column2 ... columnn
```

退出程序

```
exit
```

以下是一些辅助调试的语法

展示当前所有热数据

```
display
```

打印对应的表（table_type中，H为热数据，C为冷数据）

```
print table_type
```

