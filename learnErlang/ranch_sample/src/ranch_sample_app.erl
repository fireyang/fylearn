-module(ranch_sample_app).

-behaviour(application).

%% Application callbacks
-export([start/2, stop/1]).

%% ===================================================================
%% Application callbacks
%% ===================================================================

start(_StartType, _StartArgs) ->
    NbAcceptors = 100,
    {ok, _} = ranch:start_listener(sample, NbAcceptors, ranch_tcp,
        [{port, 5555}], sample_protocol, []),
    ranch_sample_sup:start_link().

stop(_State) ->
    ok.
