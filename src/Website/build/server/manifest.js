const manifest = (() => {
function __memo(fn) {
	let value;
	return () => value ??= (value = fn());
}

return {
	appDir: "_app",
	appPath: "_app",
	assets: new Set(["img/banner.png","robots.txt"]),
	mimeTypes: {".png":"image/png",".txt":"text/plain"},
	_: {
		client: {start:"_app/immutable/entry/start.CQuLHKO5.js",app:"_app/immutable/entry/app.C7M_tcOC.js",imports:["_app/immutable/entry/start.CQuLHKO5.js","_app/immutable/chunks/W51ZXw7t.js","_app/immutable/chunks/oSUuz_k1.js","_app/immutable/chunks/CQFaRSxQ.js","_app/immutable/entry/app.C7M_tcOC.js","_app/immutable/chunks/oSUuz_k1.js","_app/immutable/chunks/BYzeTzr1.js","_app/immutable/chunks/rNwPnN3C.js","_app/immutable/chunks/CQFaRSxQ.js","_app/immutable/chunks/4I5mrAde.js","_app/immutable/chunks/ByzFFa6p.js"],stylesheets:[],fonts:[],uses_env_dynamic_public:false},
		nodes: [
			__memo(() => import('./chunks/0-B95hFekV.js')),
			__memo(() => import('./chunks/1-BT23tUuo.js')),
			__memo(() => import('./chunks/2-CmaN0eos.js')),
			__memo(() => import('./chunks/3-BbgmOj3A.js')),
			__memo(() => import('./chunks/4-CO9Pn3o3.js')),
			__memo(() => import('./chunks/5-DZkrEso6.js')),
			__memo(() => import('./chunks/6-Bl5BXaQ9.js'))
		],
		remotes: {
			
		},
		routes: [
			{
				id: "/",
				pattern: /^\/$/,
				params: [],
				page: { layouts: [0,], errors: [1,], leaf: 3 },
				endpoint: null
			},
			{
				id: "/docs/win/[...slug]",
				pattern: /^\/docs\/win(?:\/([^]*))?\/?$/,
				params: [{"name":"slug","optional":false,"rest":true,"chained":true}],
				page: { layouts: [0,2,], errors: [1,,], leaf: 4 },
				endpoint: null
			},
			{
				id: "/sm64luaredux",
				pattern: /^\/sm64luaredux\/?$/,
				params: [],
				page: { layouts: [0,], errors: [1,], leaf: 5 },
				endpoint: null
			},
			{
				id: "/ugui",
				pattern: /^\/ugui\/?$/,
				params: [],
				page: { layouts: [0,], errors: [1,], leaf: 6 },
				endpoint: null
			}
		],
		prerendered_routes: new Set([]),
		matchers: async () => {
			
			return {  };
		},
		server_assets: {}
	}
}
})();

const prerendered = new Set([]);

const base = "";

export { base, manifest, prerendered };
//# sourceMappingURL=manifest.js.map
