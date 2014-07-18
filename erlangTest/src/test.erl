%%%-------------------------------------------------------------------
%%% @author FireYang
%%% @copyright (C) 2014, <COMPANY>
%%% @doc
%%%
%%% @end
%%% Created : 27. 六月 2014 13:00
%%%-------------------------------------------------------------------
-module(test).
-author("FireYang").
-include_lib("kernel/include/file.hrl").

%% API
-export([foo/0, helloworld/0]).

foo() -> abs(100).

helloworld() ->
  io:format("hello world fireyang").

%%include_test() -> #file_info().


