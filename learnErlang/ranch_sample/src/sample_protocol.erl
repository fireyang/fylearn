%%%-------------------------------------------------------------------
%%% @author FireYang
%%% @copyright (C) 2014, <FireYang>
%%% @doc
%%%
%%% @end
%%% Created : 30. 十二月 2014 11:09
%%%-------------------------------------------------------------------
-module(sample_protocol).
-author("FireYang").

%% API
-export([start_link/4, init/4]).

start_link(Ref, Socket, Transport, Opts) ->
  Pid = spawn_link(?MODULE, init, [Ref, Socket, Transport, Opts]),
  {ok, Pid}.

init(Ref, Socket, Transport, _Opts = []) ->
  ok = ranch:accept_ack(Ref),
  loop(Socket, Transport).


loop(Socket, Transport) ->
  case Transport:recv(Socket, 0, 5000) of
    {ok, Data} ->
      Response = list_to_binary([<<"You say ">>,  Data]),
      Transport:send(Socket, Response),
      loop(Socket, Transport);
    _ ->
      ok = Transport:close(Socket)
  end.
