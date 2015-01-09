%%%-------------------------------------------------------------------
%%% @author FireYang
%%% @copyright (C) 2014, <FireYang>
%%% @doc
%%%
%%% @end
%%% Created : 30. 十二月 2014 11:38
%%%-------------------------------------------------------------------
-module(ranch_sample).
-author("FireYang").

%% API
-export([start/0]).

start() ->
  application:start(ranch),
  application:start(ranch_sample).
